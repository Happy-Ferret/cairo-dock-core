/*
* This file is a part of the Cairo-Dock project
*
* Copyright : (C) see the 'copyright' file.
* E-mail    : see the 'copyright' file.
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 3
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef __CAIRO_DOCK_CONFIG__
#define  __CAIRO_DOCK_CONFIG__

#include <glib.h>
#include <libxml/tree.h>
#include <libxml/parser.h>

#include "cairo-dock-struct.h"
G_BEGIN_DECLS

/**
*@file cairo-dock-config.h This class manages the configuration system of Cairo-Dock.
* Cairo-Dock and any items (icons, root docks, modules, etc) are configured by conf files.
* Conf files containes some information usable by the GUI manager to build a corresponding config panel and update the conf file automatically, which relieves you from this thankless task.
*/

/*
*Recupere une cle booleene d'un fichier de cles.
*@param pKeyFile le fichier de cles.
*@param cGroupName le com du groupe.
*@param cKeyName le nom de la cle.
*@param bFlushConfFileNeeded est mis a TRUE si la cle est manquante.
*@param bDefaultValue valeur par defaut a utiliser et a inserer dans le fichier de cles au cas ou la cle est manquante.
*@param cDefaultGroupName nom de groupe alternatif, ou NULL si aucun autre.
*@param cDefaultKeyName nom de cle alternative, ou NULL si aucune autre.
*@return la valeur booleene de la cle.
*/
gboolean cairo_dock_get_boolean_key_value (GKeyFile *pKeyFile, const gchar *cGroupName, const gchar *cKeyName, gboolean *bFlushConfFileNeeded, gboolean bDefaultValue, const gchar *cDefaultGroupName, const gchar *cDefaultKeyName);
/*
*Recupere une cle entiere d'un fichier de cles.
*@param pKeyFile le fichier de cles.
*@param cGroupName le com du groupe.
*@param cKeyName le nom de la cle.
*@param bFlushConfFileNeeded est mis a TRUE si la cle est manquante.
*@param iDefaultValue valeur par defaut a utiliser et a inserer dans le fichier de cles au cas ou la cle est manquante.
*@param cDefaultGroupName nom de groupe alternatif, ou NULL si aucun autre.
*@param cDefaultKeyName nom de cle alternative, ou NULL si aucune autre.
@return la valeur entiere de la cle.
*/
int cairo_dock_get_integer_key_value (GKeyFile *pKeyFile, const gchar *cGroupName, const gchar *cKeyName, gboolean *bFlushConfFileNeeded, int iDefaultValue, const gchar *cDefaultGroupName, const gchar *cDefaultKeyName);
/*
*Recupere une cle flottante d'un fichier de cles.
*@param pKeyFile le fichier de cles.
*@param cGroupName le com du groupe.
*@param cKeyName le nom de la cle.
*@param bFlushConfFileNeeded est mis a TRUE si la cle est manquante.
*@param fDefaultValue valeur par defaut a utiliser et a inserer dans le fichier de cles au cas ou la cle est manquante.
*@param cDefaultGroupName nom de groupe alternatif, ou NULL si aucun autre.
*@param cDefaultKeyName nom de cle alternative, ou NULL si aucune autre.
*@return la valeur flottante de la cle.
*/
double cairo_dock_get_double_key_value (GKeyFile *pKeyFile, const gchar *cGroupName, const gchar *cKeyName, gboolean *bFlushConfFileNeeded, double fDefaultValue, const gchar *cDefaultGroupName, const gchar *cDefaultKeyName);
/*
*Recupere une cle d'un fichier de cles sous la forme d'une chaine de caractere.
*@param pKeyFile le fichier de cles.
*@param cGroupName le com du groupe.
*@param cKeyName le nom de la cle.
*@param bFlushConfFileNeeded est mis a TRUE si la cle est manquante.
*@param cDefaultValue valeur par defaut a utiliser et a inserer dans le fichier de cles au cas ou la cle est manquante.
*@param cDefaultGroupName nom de groupe alternatif, ou NULL si aucun autre.
*@param cDefaultKeyName nom de cle alternative, ou NULL si aucune autre.
*@return la chaine de caractere nouvellement allouee correspondante a la cle.
*/
gchar *cairo_dock_get_string_key_value (GKeyFile *pKeyFile, const gchar *cGroupName, const gchar *cKeyName, gboolean *bFlushConfFileNeeded, const gchar *cDefaultValue, const gchar *cDefaultGroupName, const gchar *cDefaultKeyName);
/*
*Recupere une cle d'un fichier de cles sous la forme d'un tableau d'entiers.
*@param pKeyFile le fichier de cles.
*@param cGroupName le com du groupe.
*@param cKeyName le nom de la cle.
*@param bFlushConfFileNeeded est mis a TRUE si la cle est manquante.
*@param iValueBuffer tableau qui sera rempli.
*@param iNbElements nombre d'elements a recuperer; c'est le nombre d'elements du tableau passe en entree.
*@param iDefaultValues valeur par defaut a utiliser et a inserer dans le fichier de cles au cas ou la cle est manquante.
*@param cDefaultGroupName nom de groupe alternatif, ou NULL si aucun autre.
*@param cDefaultKeyName nom de cle alternative, ou NULL si aucune autre.
*/
void cairo_dock_get_integer_list_key_value (GKeyFile *pKeyFile, const gchar *cGroupName, const gchar *cKeyName, gboolean *bFlushConfFileNeeded, int *iValueBuffer, guint iNbElements, int *iDefaultValues, const gchar *cDefaultGroupName, const gchar *cDefaultKeyName);
/*
*Recupere une cle d'un fichier de cles sous la forme d'un tableau de doubles.
*@param pKeyFile le fichier de cles.
*@param cGroupName le com du groupe.
*@param cKeyName le nom de la cle.
*@param bFlushConfFileNeeded est mis a TRUE si la cle est manquante.
*@param fValueBuffer tableau qui sera rempli.
*@param iNbElements nombre d'elements a recuperer; c'est le nombre d'elements du tableau passe en entree.
*@param fDefaultValues valeur par defaut a utiliser et a inserer dans le fichier de cles au cas ou la cle est manquante.
*@param cDefaultGroupName nom de groupe alternatif, ou NULL si aucun autre.
*@param cDefaultKeyName nom de cle alternative, ou NULL si aucune autre.
*/
void cairo_dock_get_double_list_key_value (GKeyFile *pKeyFile, const gchar *cGroupName, const gchar *cKeyName, gboolean *bFlushConfFileNeeded, double *fValueBuffer, guint iNbElements, double *fDefaultValues, const gchar *cDefaultGroupName, const gchar *cDefaultKeyName);
/*
*Recupere une cle d'un fichier de cles sous la forme d'un tableau de chaines de caracteres.
*@param pKeyFile le fichier de cles.
*@param cGroupName le com du groupe.
*@param cKeyName le nom de la cle.
*@param bFlushConfFileNeeded est mis a TRUE si la cle est manquante.
*@param length nombre de chaines de caracteres recuperees.
*@param cDefaultValues valeur par defaut a utiliser et a inserer dans le fichier de cles au cas ou la cle est manquante.
*@param cDefaultGroupName nom de groupe alternatif, ou NULL si aucun autre.
*@param cDefaultKeyName nom de cle alternative, ou NULL si aucune autre.
*@return un tableau de chaines de caracteres; a liberer avec g_strfreev().
*/
gchar **cairo_dock_get_string_list_key_value (GKeyFile *pKeyFile, const gchar *cGroupName, const gchar *cKeyName, gboolean *bFlushConfFileNeeded, gsize *length, const gchar *cDefaultValues, const gchar *cDefaultGroupName, const gchar *cDefaultKeyName);

void cairo_dock_get_size_key_value (GKeyFile *pKeyFile, const gchar *cGroupName, const gchar *cKeyName, gboolean *bFlushConfFileNeeded, gint iDefaultSize, const gchar *cDefaultGroupName, const gchar *cDefaultKeyName, int *iWidth, int *iHeight);
/*
*Recupere une cle d'un fichier de cles sous la forme d'un chemin de fichier complet. La clé peut soit être un fichier relatif au thème courant, soit un chemin començant par '~', soit un chemin complet, soit vide auquel cas le chemin d'un fichier par defaut est renvoye s'il est specifie.
*@param pKeyFile le fichier de cles.
*@param cGroupName le com du groupe.
*@param cKeyName le nom de la cle.
*@param bFlushConfFileNeeded est mis a TRUE si la cle est manquante.
*@param cDefaultGroupName nom de groupe alternatif, ou NULL si aucun autre.
*@param cDefaultKeyName nom de cle alternative, ou NULL si aucune autre.
*@param cDefaultDir si la cle est vide, on prendra un fichier par defaut situe dans ce repertoire. (optionnel)
*@param cDefaultFileName si la cle est vide, on prendra ce fichier par defaut dans le repertoire defini ci-dessus. (optionnel)
*@return le chemin complet du fichier, a liberer avec g_free().
*/
gchar *cairo_dock_get_file_path_key_value (GKeyFile *pKeyFile, const gchar *cGroupName, const gchar *cKeyName, gboolean *bFlushConfFileNeeded, const gchar *cDefaultGroupName, const gchar *cDefaultKeyName, const gchar *cDefaultDir, const gchar *cDefaultFileName);

#define cairo_dock_get_size_key_value_helper(pKeyFile, cGroupName, cKeyPrefix, bFlushConfFileNeeded, iWidth, iHeight) \
	cairo_dock_get_size_key_value (pKeyFile, cGroupName, cKeyPrefix"size", &bFlushConfFileNeeded, 0, NULL, NULL, &iWidth, &iHeight);\
	if (iWidth == 0) {\
		iWidth = g_key_file_get_integer (pKeyFile, cGroupName, cKeyPrefix"width", NULL);\
		if (iWidth != 0) {\
			iHeight = g_key_file_get_integer (pKeyFile, cGroupName, cKeyPrefix"height", NULL);\
			int iSize[2] = {iWidth, iHeight};\
			g_key_file_set_integer_list (pKeyFile, cGroupName, cKeyPrefix"size", iSize, 2); } }

void cairo_dock_get_color_key_value (GKeyFile *pKeyFile, const gchar *cGroupName, const gchar *cKeyName, gboolean *bFlushConfFileNeeded, GldiColor *fValueBuffer, GldiColor *fDefaultValues, const gchar *cDefaultGroupName, const gchar *cDefaultKeyName);


/** Load the current theme. This will (re)load all the parameters of Cairo-Dock and all the plug-ins, as if you just started the dock.
*/
void cairo_dock_load_current_theme (void);


/** Say if Cairo-Dock is loading.
*@return TRUE if the global config is being loaded (this happens when a theme is loaded).
*/
gboolean cairo_dock_is_loading (void);


/** Decrypt a string (uses DES-encryption from libcrypt).
*@param cEncryptedString the encrypted string.
*@param cDecryptedString the decrypted string.
*/
void cairo_dock_decrypt_string( const gchar *cEncryptedString,  gchar **cDecryptedString );

/** Encrypt a string (uses DES-encryption from libcrypt).
*@param cDecryptedString the decrypted string.
*@param cEncryptedString the encrypted string.
*/
void cairo_dock_encrypt_string( const gchar *cDecryptedString,  gchar **cEncryptedString );


xmlDocPtr cairo_dock_open_xml_file (const gchar *cDataFilePath, const gchar *cRootNodeName, xmlNodePtr *root_node, GError **erreur);

void cairo_dock_close_xml_file (xmlDocPtr doc);


G_END_DECLS
#endif

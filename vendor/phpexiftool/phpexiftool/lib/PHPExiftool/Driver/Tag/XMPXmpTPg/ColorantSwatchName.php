<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\XMPXmpTPg;

use PHPExiftool\Driver\AbstractTag;

class ColorantSwatchName extends AbstractTag
{

    protected $Id = 'ColorantsSwatchName';

    protected $Name = 'ColorantSwatchName';

    protected $FullName = 'XMP::xmpTPg';

    protected $GroupName = 'XMP-xmpTPg';

    protected $g0 = 'XMP';

    protected $g1 = 'XMP-xmpTPg';

    protected $g2 = 'Image';

    protected $Type = 'string';

    protected $Writable = true;

    protected $Description = 'Colorant Swatch Name';

    protected $flag_List = true;

}

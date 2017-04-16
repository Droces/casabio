<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\XMPPdf;

use PHPExiftool\Driver\AbstractTag;

class ModDate extends AbstractTag
{

    protected $Id = 'ModDate';

    protected $Name = 'ModDate';

    protected $FullName = 'XMP::pdf';

    protected $GroupName = 'XMP-pdf';

    protected $g0 = 'XMP';

    protected $g1 = 'XMP-pdf';

    protected $g2 = 'Image';

    protected $Type = 'date';

    protected $Writable = true;

    protected $Description = 'Mod Date';

    protected $local_g2 = 'Time';

}